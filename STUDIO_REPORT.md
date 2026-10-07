# Studio Deliverable Report: Algorithmic Optimization & Portfolio Integration

**Author:** Ashwin Rajesh Sam  
**SRN:** R25EJ019  
**Course:** Portfolio Building (B25CS0311) — Activity 8  
**Institution:** REVA University, School of Computing and Information Technology  
**HackerRank Profile:** `https://www.hackerrank.com/profile/AshwinRajeshSam`  
**GitHub Repository:** `https://github.com/AshwinRajeshSam/activity-8-hackerrank-portfolio`  

---

## 1. Algorithmic Optimization Reflection (200 Words)
Throughout this studio activity, solving the five curated challenges provided concrete exposure to the tangible impact of algorithmic complexity and hardware cache awareness. In *Diagonal Difference*, rather than executing nested $O(N^2)$ loops across all matrix coordinates, primary and secondary diagonals were traversed in a unified single pass of $O(N)$ operations with $O(1)$ auxiliary memory. In *Dynamic Array*, managing nested dynamic sequences illuminated the trade-off of amortized $O(1)$ geometric array resizing versus frequent heap reallocations. 

Similarly, working with string manipulation in *Time Conversion* and *Sparse Arrays* emphasized boundary validation and memory alignment in C. Rather than resorting to naive multi-pass scans, analyzing frequency distributions with direct memory addressing proved crucial for meeting HackerRank's stringent sub-second test execution constraints. Moving beyond theoretical Big-O notation to empirical execution has demonstrated how data structure selection dictates both runtime performance and cache locality. Maintaining an active, documented problem-solving repository on GitHub while securing the 3-Star Problem Solving Badge establishes verifiable engineering competence for placement pre-screening and technical interviews.

---

## 2. Technical Complexity & Optimization Breakdown

### Matrix Traversal Efficiency:
- **Naive Approach:** Nested loop `for i: 0..N, for j: 0..N` inspecting `if (i == j)` and `if (i + j == N - 1)` $\to O(N^2)$ memory reads.
- **Optimized Approach:** Single index counter $i$ reading `arr[i][i]` and `arr[i][N - 1 - i]` $\to O(N)$ memory reads, achieving a $N\times$ speedup with perfect linear CPU cache pre-fetching.

### Dynamic Vector Doubling:
- Dynamic arrays implemented with geometric expansion (`capacity *= 2`) ensures that $N$ sequential insertions incur only $O(N)$ total copy operations, resulting in amortized $O(1)$ push time compared to quadratic degradation in static reallocations.
