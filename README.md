<p align="center">
  <img src="https://img.shields.io/badge/Algorithm-Rabin--Karp-7C3AED?style=for-the-badge&logo=databricks&logoColor=white" />
  <img src="https://img.shields.io/badge/Frontend-HTML%2FCSS%2FJS-EC4899?style=for-the-badge&logo=html5&logoColor=white" />
  <img src="https://img.shields.io/badge/Visualizer-Interactive-F97316?style=for-the-badge&logo=openlayers&logoColor=white" />
</p>

# 🧬 Rabin-Karp Algorithm Visualizer

An **interactive, step-by-step visualizer** for the **Rabin-Karp string matching algorithm** — built with a premium dark-mode UI featuring glassmorphism, gradient accents, and micro-animations.

> Built as a project for **Design and Analysis of Algorithms (DAA)** to demonstrate how the Rabin-Karp rolling hash algorithm works visually.

---

## 🎯 What It Does

Enter any **text** and **pattern**, press **▶ Play**, and watch the algorithm:

1. Compute the **pattern hash** and **initial window hash**
2. **Slide** the window one position at a time with rolling hash updates
3. **Compare hashes** — mismatches flash red, hash matches flash amber for verification
4. **Confirm matches** — verified matches glow green with a confetti burst
5. **Detect false positives** — hash collisions that fail string verification are flagged

All with live hash values, a step log, and real-time statistics.

---

## 🧠 The Rabin-Karp Algorithm

### Overview

The **Rabin-Karp algorithm** is a string searching algorithm that uses **hashing** to find pattern occurrences in text. Created by Richard M. Karp and Michael O. Rabin (1987).

### How It Works

1. **Computes a hash** of the pattern
2. **Computes a hash** of the current text window (same length as pattern)
3. **Compares hashes** — if they match, verifies with a full string comparison
4. **Rolls the hash forward** in O(1) using the rolling hash formula

### Rolling Hash Formula

```
hash(s[i+1..i+m]) = (hash(s[i..i+m-1]) - s[i] × BASE^(m-1)) × BASE + s[i+m]  mod PRIME
```

Constants: `BASE = 256`, `PRIME = 101`

### Complexity Analysis

| Metric | Value |
|--------|-------|
| **Best Case** | O(n + m) — where n = text length, m = pattern length |
| **Average Case** | O(n + m) — with a good hash function |
| **Worst Case** | O(n × m) — many hash collisions (rare with good prime) |
| **Space** | O(1) additional space |

---

## ✨ Visualizer Features

| Feature | Description |
|---------|-------------|
| **Character Tiles** | Each text character displayed as an individual tile with index |
| **Sliding Window** | Pattern-length window highlighted with violet glow, slides step-by-step |
| **Visual States** | 🔴 Red flash + shake = mismatch · 🟡 Amber = verifying · 🟢 Green = confirmed match |
| **Confetti Burst** | 24-particle gradient explosion on match confirmation |
| **Live Hash Display** | Window hash vs pattern hash with pulse animation on change |
| **Hash Match Indicator** | ✅ / ❌ with color coding |
| **Verification Status** | Shows ✅ MATCH or ❌ FALSE POSITIVE after string comparison |
| **Progress Bar** | Gradient bar (violet → pink → coral) showing algorithm progress |
| **Step Log** | Terminal-style monospace log of every algorithmic operation |
| **Play / Pause / Reset** | Full animation control |
| **Speed Slider** | 5 levels: 800ms (slow) → 100ms (fast) |
| **Info Panel** | Collapsible sidebar with algorithm explanation, formula, and complexity table |

---

## 🎨 Design

- **Dark theme**: `#0A0A0F` base, `#12121A` cards, `#1A1A26` elevated
- **Gradient accent**: Electric violet `#7C3AED` → Hot pink `#EC4899` → Coral `#F97316`
- **Glassmorphism**: `backdrop-filter: blur(24px)` panels
- **Typography**: Inter + JetBrains Mono (stats/log)
- **Responsive**: Adapts to mobile and desktop

---

## 📁 Project Structure

```
RabinKarp/
├── public/
│   └── index.html       # Self-contained visualizer (HTML + CSS + JS)
├── server.js             # Minimal Express static server
├── package.json          # Node.js dependencies
└── README.md             # This file
```

---

## ⚙️ Prerequisites

- [Node.js](https://nodejs.org/) (v14 or higher)
- A modern web browser

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/Tarika06/RabinKarp.git
cd RabinKarp
```

### 2. Install Dependencies

```bash
npm install
```

### 3. Start the Server

```bash
npm start
```

### 4. Open in Browser

Navigate to **http://localhost:3000** — the visualizer loads directly.

> **Alternative:** Since the visualizer is fully self-contained, you can also just open `public/index.html` directly in your browser — no server needed.

---

## 🎮 Usage

1. **Enter text** — Type or paste any string in the "Text" field
2. **Enter pattern** — Type the substring to search for
3. **Click ▶ Play** — Watch the algorithm animate step by step
4. **Adjust speed** — Use the slider (1 = slow, 5 = fast)
5. **Pause / Resume** — Click ⏸ Pause to freeze, ▶ Resume to continue
6. **Reset** — Click ↺ Reset to start over with new inputs
7. **Learn** — Click the **?** button (top-right) for the algorithm explanation

### Example

```
Text:    "hello world badword here"
Pattern: "badword"

→ 18 comparisons, 1 match found at index 12
→ "badword" tiles glow green with confetti
```

---

## 🛠️ Tech Stack

| Layer | Technology | Purpose |
|-------|------------|---------|
| Visualizer | HTML5, CSS3, JavaScript | Self-contained algorithm visualization |
| Server | Node.js, Express.js | Static file serving (optional) |
| Fonts | Inter, JetBrains Mono | Typography (Google Fonts) |

---

## 📚 References

1. Karp, R.M.; Rabin, M.O. (1987). *"Efficient randomized pattern-matching algorithms"*. IBM Journal of Research and Development.
2. Cormen, T.H.; Leiserson, C.E.; Rivest, R.L.; Stein, C. *"Introduction to Algorithms"* (CLRS), Chapter 32: String Matching.
3. [GeeksforGeeks — Rabin-Karp Algorithm](https://www.geeksforgeeks.org/rabin-karp-algorithm-for-pattern-searching/)

---

## 📄 License

This project is developed for educational purposes as part of the **Design and Analysis of Algorithms** course.

---

<p align="center">
  <sub>Built with 💜 using the Rabin-Karp Algorithm</sub>
</p>
