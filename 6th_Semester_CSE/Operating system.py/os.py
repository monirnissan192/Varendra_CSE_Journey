process=[]
n=int(input("Enter number of Processes : "))
for i in range(n):
    pid=input(f"Enter the number of Porcess Id {i+1}:");
    at=int(input("Arival Time: "))
    bt=int(input("Burst Time: "))
    process.append([pid, at, bt])
print("\nProcess List:")
print("PID\tAT\tBT")
for p in process:
    print(f"{p[0]}\t{p[1]}\t{p[2]}")
