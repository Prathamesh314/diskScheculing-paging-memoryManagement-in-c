# diskScheculing-paging-memoryManagement-in-c
This Repository contains codes for First Fit memory management, Optimal Paging policy and First Come First Serve Disk Scheduling alorithms


#  Theory

## Disk Scheduling Algorithms

Disk scheduling algorithms are algorithms used by operating systems to determine the order in which disk I/O requests are serviced by a hard disk drive. The goal of these algorithms is to optimize the disk access and minimize the disk seek time, which is the time taken by the disk's read/write head to move to the desired location on the disk.

Here are some commonly used disk scheduling algorithms:

1. FCFS (First-Come, First-Served): This is the simplest disk scheduling algorithm, where the I/O requests are serviced in the order they arrive. It doesn't consider the location of the requests on the disk, which can lead to poor performance if the requests are scattered across the disk.

2. SSTF (Shortest Seek Time First): This algorithm selects the I/O request that requires the least disk head movement from its current position. It aims to minimize the seek time by always selecting the request closest to the current disk head position. This algorithm may result in starvation for requests located far from the disk head.

3. SCAN: The SCAN algorithm works like an elevator, moving the disk head in one direction (e.g., from the outermost track to the innermost track) and then reversing direction when it reaches the end. It services the requests in the order of their location on the disk in the direction of the head movement. This algorithm reduces the average response time for requests located closer to the disk head, but requests at the extreme ends may experience higher wait times.

4. C-SCAN (Circular SCAN): Similar to the SCAN algorithm, the C-SCAN algorithm also moves the disk head in one direction. However, when it reaches the end, it immediately jumps to the other end without servicing any requests in between. It provides a more uniform response time for all requests compared to SCAN.

5. C-LOOK (Circular LOOK): The C-LOOK algorithm is a variation of the SCAN algorithm. Instead of moving to the end of the disk, it only goes as far as the last request in the current direction. It reverses the direction without moving to the end. This algorithm reduces the seek time and provides a better response time than SCAN.

6. N-Step SCAN: This algorithm divides the disk into multiple zones and scans each zone using the SCAN algorithm. It allows prioritization of certain requests by specifying the number of steps to be taken in each zone. This algorithm provides better control over performance and allows different response time guarantees for different requests.

These are just a few examples of disk scheduling algorithms. The choice of algorithm depends on various factors, such as the workload characteristics, the disk drive's physical properties, and the specific performance requirements of the system.

## Paging

Page replacement policies are algorithms used in operating systems to determine which page(s) should be evicted from memory when a page fault occurs and new pages need to be loaded. These policies aim to minimize the number of page faults and optimize memory utilization. Here are some commonly used page replacement policies:

Optimal Page Replacement: This theoretical algorithm selects the page that will not be used for the longest period of time in the future. However, it requires knowledge of future memory references, which is usually not feasible in real systems. Optimal page replacement serves as a performance benchmark for other algorithms.

FIFO (First-In-First-Out): The FIFO algorithm replaces the page that has been in memory the longest. It maintains a queue of pages, and when a page fault occurs, the page at the front of the queue (the oldest page) is evicted. FIFO is simple to implement but suffers from the "Belady's Anomaly," where increasing the number of frames can lead to an increase in page faults.

LRU (Least Recently Used): The LRU algorithm replaces the page that has not been accessed for the longest time. It requires maintaining a record of the order in which pages were last accessed. When a page fault occurs, the page that was least recently used is evicted. LRU is effective in capturing temporal locality but can be computationally 

## Memory Management Algorithms

Memory management algorithms are techniques used by operating systems to efficiently allocate and manage memory resources in a computer system. These algorithms ensure that processes have the required memory space for execution and optimize memory utilization. Here are some commonly used memory management algorithms

Variable Partitioning: Variable partitioning overcomes the limitation of fixed partitioning by dynamically dividing the memory into variable-sized partitions based on process requirements. Various algorithms are used for allocating and managing variable-sized partitions, such as:

First-Fit: The first-fit algorithm allocates the first available partition that is large enough to accommodate the process. It starts searching from the beginning of the memory.

Best-Fit: The best-fit algorithm allocates the smallest available partition that is large enough to accommodate the process. It searches the entire memory to find the best fit.

Worst-Fit: The worst-fit algorithm allocates the largest available partition to the process. It aims to minimize external fragmentation by selecting the largest possible partition, which may be split into smaller fragments.
