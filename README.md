# Leetcode-368.-Largest-Divisible-Subset
# 🔢 Largest Divisible Subset

This repository contains **two approaches** to solve the **Largest Divisible Subset** problem.

A **divisible subset** is a subset of integers such that for every pair `(a, b)` in the subset, either:

```
a % b == 0 or b % a == 0
```

---

## 🚀 Problem Statement

Given an array of **positive integers**, return the **largest subset** such that every pair `(Si, Sj)` of elements satisfies:

```
Si % Sj == 0 or Sj % Si == 0
```

If there are multiple solutions, return any of them.

---

## 🧠 Approach 1: Brute Force using Recursion (Top-Down)

### 📄 File: `bruteforce_recursion.cpp`

### 🔍 Key Concepts:

* Uses **recursive backtracking** to try all subsets
* Tracks the largest subset where all elements are divisible by the previous element

### 🛠️ Logic:

1. Sort the array for easier divisibility checks ✅
2. At each index, try two choices:

   * Include the current element if it's divisible by the last selected one
   * Skip the current element
3. Track the longest valid subset using recursion

### 📦 Time Complexity:

* Worst-case: **Exponential** `O(2^n)`
* Suitable only for small input sizes

---

## ⚡ Approach 2: Bottom-Up Dynamic Programming

### 📄 File: `bottom_up_dp.cpp`

### 🔍 Key Concepts:

* Uses **DP** to track the length of the largest subset ending at each index
* Uses an auxiliary `prev[]` array to reconstruct the path

### 🛠️ Logic:

1. Sort the array in ascending order
2. Use `dp[i]` to store the length of the largest divisible subset ending at `i`
3. Use `prev[i]` to store the index of the previous element in the subset
4. Track the maximum length and its ending index
5. Reconstruct the subset by tracing back from the `prev[]` array

### 📦 Time Complexity:

* Time: **O(n^2)**
* Space: **O(n)**

---

## 🔍 Example

```cpp
Input: nums = [1, 2, 4, 8]
Output: [1, 2, 4, 8]
```

All elements are divisible: 2 % 1 == 0, 4 % 2 == 0, 8 % 4 == 0 ✅

---

## ✨ Tips

* Always **sort** the array before checking divisibility
* Use DP for optimal performance on large arrays

---

## 📜 License

MIT License. Free to use and contribute!

---

Happy Coding! 🎯🧮💻
