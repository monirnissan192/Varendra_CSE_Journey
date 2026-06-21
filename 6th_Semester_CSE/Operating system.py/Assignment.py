import copy
import matplotlib.pyplot as plt

class MemorySimulator:
    def __init__(self, memory_blocks):
        self.original_blocks = memory_blocks
        self.blocks = []
        self.reset_memory()

    def reset_memory(self):
        self.blocks = copy.deepcopy(self.original_blocks)

    def display_status(self, process_sizes, allocation, algo_name):
        print(f"\n{'-'*60}")
        print(f"--- Allocation Status: {algo_name} ---")
        print(f"{'-'*60}")
        print("Process No.\tProcess Size\tBlock No.\tBlock Size\tInternal Fragment")
        
        total_internal_frag = 0
        unallocated_processes = []

        for i in range(len(process_sizes)):
            if allocation[i] != -1:
                block_idx = allocation[i]
                block_size = self.original_blocks[block_idx]
                frag = block_size - process_sizes[i]
                total_internal_frag += frag
                print(f" {i+1}\t\t{process_sizes[i]}\t\t{block_idx+1}\t\t{block_size}\t\t{frag}")
            else:
                print(f" {i+1}\t\t{process_sizes[i]}\t\tNot Allocated\t-\t\t-")
                unallocated_processes.append(i+1)

        print("\n--- Fragmentation Analysis ---")
        print(f"Total Internal Fragmentation: {total_internal_frag}")
        
        total_free_space = sum(self.blocks)
        print(f"Total Remaining Free Space: {total_free_space}")
        
        if unallocated_processes:
            for p_idx in unallocated_processes:
                p_size = process_sizes[p_idx-1]
                if total_free_space >= p_size:
                    print(f"[!] External Fragmentation Alert: Process {p_idx} ({p_size}) could fit, but contiguous blocks are too small.")
                else:
                    print(f"[-] Process {p_idx} ({p_size}) cannot fit. Insufficient total memory.")
        else:
            print("[+] No External Fragmentation present. All processes allocated successfully.")

    def visualize_memory_gui(self, title):
        """Uses matplotlib to generate a graphical representation of the memory blocks."""
        plt.figure(figsize=(10, 2))
        left = 0

        for i in range(len(self.original_blocks)):
            total_size = self.original_blocks[i]
            free_space = self.blocks[i]
            used_space = total_size - free_space

            # Draw the full block background as lightgray (representing total capacity / free space)
            plt.barh(y=0, width=total_size, left=left, color="lightgray", edgecolor='black')
            
            # Draw the allocated portion as skyblue (representing the process inside the block)
            if used_space > 0:
                plt.barh(y=0, width=used_space, left=left, color="skyblue", edgecolor='black')
            
            # Label the block in the center
            plt.text(left + total_size/2, 0, f"B{i+1}\n({total_size})", ha='center', va='center', fontsize=9)
            
            left += total_size

        plt.yticks([])
        plt.title(title)
        plt.xlabel("Memory Capacity (KB)")
        plt.tight_layout()
        plt.show()

    def first_fit(self, process_sizes):
        self.reset_memory()
        n = len(process_sizes)
        m = len(self.blocks)
        allocation = [-1] * n

        for i in range(n):
            for j in range(m):
                if self.blocks[j] >= process_sizes[i]:
                    allocation[i] = j
                    self.blocks[j] -= process_sizes[i]
                    break
        
        self.display_status(process_sizes, allocation, "First Fit")
        self.visualize_memory_gui("First Fit Allocation Status")

    def best_fit(self, process_sizes):
        self.reset_memory()
        n = len(process_sizes)
        m = len(self.blocks)
        allocation = [-1] * n

        for i in range(n):
            best_idx = -1
            for j in range(m):
                if self.blocks[j] >= process_sizes[i]:
                    if best_idx == -1 or self.blocks[j] < self.blocks[best_idx]:
                        best_idx = j
            
            if best_idx != -1:
                allocation[i] = best_idx
                self.blocks[best_idx] -= process_sizes[i]

        self.display_status(process_sizes, allocation, "Best Fit")
        self.visualize_memory_gui("Best Fit Allocation Status")

if __name__ == "__main__":
    initial_memory_blocks = [100, 500, 200, 300, 600]
    incoming_processes = [212, 417, 112, 426]

    print("=== OS SIMULATOR: MODULE 2 (MEMORY MANAGEMENT) ===")
    print(f"Initial Memory Blocks: {initial_memory_blocks}")
    print(f"Incoming Process Sizes: {incoming_processes}")

    simulator = MemorySimulator(initial_memory_blocks)
    
    # Run algorithms - this will print the tables to the terminal AND pop up the graphs
    simulator.first_fit(incoming_processes)
    simulator.best_fit(incoming_processes)