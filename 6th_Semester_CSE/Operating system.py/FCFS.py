process = []
n = int(input("Enter the number of inputs: "))

for i in range(n):
    pid = input(f"Enter the process ID {i+1}: ")
    # FIX 1: Converted arrival and burst times to integers
    at = int(input("Enter the arrival time: "))
    bt = int(input("Enter the burst time: "))
    process.append([pid, at, bt])

print("\nProcess List:")
print("PID\tAT\tBT")
for p in process:
    print(f"{p[0]}\t{p[1]}\t{p[2]}")

def fcfs(process):
    process.sort(key=lambda x: x[1])
    
    # FIX 2: Initialize time as an integer, not a list []
    time = 0 
    gant = []
    wat_listt = []
    tat_list = []
    
    print("\nPID\tAT\tBT\tWT\tTAT")
    for p in process:
        pid, at, bt = p
        
        if time < at:
            time = at
            
        start = time
        wt = start - at
        tat = wt + bt
        end = start + bt

        # FIX 3: Pass a single list/tuple to append()
        gant.append([pid, start, end]) 
        wat_listt.append(wt)
        tat_list.append(tat)
        time = end
        
        print(f"{pid}\t{at}\t{bt}\t{wt}\t{tat}")

    print(f"\nAverage WT: {sum(wat_listt)/len(wat_listt):.2f}")
    print(f"Average TAT: {sum(tat_list)/len(tat_list):.2f}")

# FIX 4: Actually call the function to run it
fcfs(process)