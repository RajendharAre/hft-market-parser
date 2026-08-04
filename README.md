# NASDAQ TotalView-ITCH Replay Engine

> **A modular market data replay engine built in Modern C++20 for parsing, decoding, and replaying real NASDAQ TotalView-ITCH 5.0 binary market data.**

[![C++20](https://img.shields.io/badge/C%2B%2B-20-blue.svg)](https://en.cppreference.com/w/cpp/20)
[![Build System](https://img.shields.io/badge/Build-CMake-brightgreen)](https://cmake.org/)
[![Platform](https://img.shields.io/badge/Platform-Linux%20%7C%20WSL-orange)]()
[![License](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)

---

## 📌 Overview

This project implements a **high-performance market data replay engine** capable of parsing and decoding **NASDAQ TotalView-ITCH 5.0** binary market data. It reconstructs an **in-memory limit order book**, maintains replay statistics, and processes **hundreds of millions of real exchange messages** using a modular Modern C++20 architecture.

The primary objective of this project is to explore **systems programming**, **binary protocol parsing**, **market microstructure**, and **performance-oriented software design** by building a replay engine similar to those used in quantitative trading and electronic exchange infrastructure.

---

> **Current Status:** 🚧 Version 1.0 (Core Replay Engine Complete)

## 🎯 Project Objectives

Financial exchanges such as **NASDAQ** generate billions of market events every trading day. These events are distributed using the **NASDAQ TotalView-ITCH 5.0** protocol, a compact binary format that delivers real-time information about order submissions, executions, cancellations, and other market activities.

The primary objective of this project is to build a modular replay engine capable of reading and processing real NASDAQ TotalView-ITCH market data while reconstructing an in-memory **Limit Order Book (LOB)**. Beyond protocol parsing, this project explores the software engineering principles behind modern market data systems, including efficient binary parsing, modular architecture, replay pipelines, and performance-oriented system design.

This project is designed as a learning and engineering exercise to better understand how modern electronic trading systems ingest, decode, and process high-volume financial market data.

---

### 🎯 Goals

- Parse real **NASDAQ TotalView-ITCH 5.0** binary datasets.
- Decode multiple ITCH message types into structured Modern C++20 objects.
- Reconstruct and maintain an in-memory **Limit Order Book (LOB)** during replay.
- Collect replay statistics for processed market events.
- Build a modular and extensible architecture that simplifies support for additional ITCH message types.
- Provide a solid foundation for future performance optimizations such as **memory-mapped I/O (`mmap`)**, **cache-aware programming**, **lock-free data structures**, and **multi-threaded replay**.

---

### 📚 Learning Outcomes

This project demonstrates practical experience with:

- Modern C++20
- Systems Programming
- Binary Protocol Parsing
- Financial Market Data Processing
- Limit Order Book Reconstruction
- Performance-Oriented Software Design
- Modular Software Architecture
- CMake Build System
- Git & GitHub Workflow

---

### 🚀 Long-Term Vision

The long-term vision of this project is to evolve from a replay engine into a comprehensive market data platform capable of supporting the complete NASDAQ TotalView-ITCH protocol, advanced replay analytics, performance benchmarking, visualization dashboards, and low-latency optimization techniques commonly used in quantitative trading infrastructure.

## ✨ Core Features

### 📂 Binary Market Data Processing
- Reads and processes real **NASDAQ TotalView-ITCH 5.0** binary datasets.
- Supports efficient sequential replay of large-scale market data files.
- Handles datasets containing **hundreds of millions of exchange messages**.

### 🔍 ITCH Protocol Decoder
- Decodes binary ITCH messages into strongly typed C++ structures.
- Currently supports the following message types:
  - **S** — System Event
  - **R** — Stock Directory
  - **A** — Add Order
  - **E** — Order Executed
  - **X** — Order Cancel

### 📖 Replay Engine
- Replays market events in the original order they appear within the dataset.
- Maintains a continuous event-processing pipeline from file ingestion to order book updates.
- Supports configurable replay limits for faster development and testing.

### 📈 In-Memory Limit Order Book
- Maintains active orders using an efficient hash-based lookup structure.
- Supports:
  - Order insertion
  - Partial executions
  - Complete executions
  - Order cancellations
- Provides real-time tracking of active orders during replay.

### 📊 Replay Statistics
Collects runtime statistics including:

- Total messages processed
- System Event messages
- Stock Directory messages
- Add Order messages
- Executed Order messages
- Cancel Order messages
- Unknown message types
- Active orders remaining after replay
- Replay execution time
- Processing throughput (messages/second)

### ⚙️ Modern C++20 Implementation
- Modular project architecture
- Packed protocol structures for binary parsing
- Endian-safe data conversion utilities
- CMake-based build system
- Portable Linux / WSL development environment

### 🏗️ Extensible Design
The codebase is organized into independent modules, making it straightforward to extend with:

- Additional ITCH message types
- Performance optimizations
- Advanced order book functionality
- Replay analytics
- Benchmarking tools

## 🏗️ System Architecture

The replay engine is organized as a modular processing pipeline where each component has a single responsibility. Incoming binary market data flows through a sequence of stages, allowing each module to focus on parsing, decoding, processing, or reporting.

```text
                     NASDAQ TotalView-ITCH 5.0 Dataset
                                   │
                                   ▼
                        ┌─────────────────────┐
                        │     ITCH Reader     │
                        │  Binary File Input  │
                        └──────────┬──────────┘
                                   │
                                   ▼
                        ┌─────────────────────┐
                        │    ITCH Decoder     │
                        │ Message Extraction  │
                        └──────────┬──────────┘
                                   │
                    ┌──────────────┴──────────────┐
                    │                             │
                    ▼                             ▼
        ┌─────────────────────┐       ┌─────────────────────┐
        │   Replay Statistics │       │  Limit Order Book   │
        │ Message Counters    │       │ Active Order State  │
        └──────────┬──────────┘       └──────────┬──────────┘
                   │                             │
                   └──────────────┬──────────────┘
                                  ▼
                      ┌─────────────────────────┐
                      │     Replay Summary      │
                      │ Statistics & Metrics    │
                      └─────────────────────────┘
```

---

### 🔄 Processing Pipeline

The replay engine follows a deterministic event-processing pipeline:

1. **ITCH Reader**
   - Opens the binary NASDAQ dataset.
   - Reads one ITCH message at a time.
   - Passes raw message bytes to the decoder.

2. **ITCH Decoder**
   - Identifies the ITCH message type.
   - Converts raw binary data into structured C++ objects.
   - Dispatches each decoded message to the appropriate processing module.

3. **Limit Order Book**
   - Maintains the current state of active market orders.
   - Updates order state based on Add, Execute, and Cancel messages.
   - Tracks the remaining active orders throughout replay.

4. **Statistics Engine**
   - Records replay metrics during execution.
   - Counts each supported ITCH message type.
   - Measures replay duration and processing throughput.

5. **Replay Summary**
   - Generates a consolidated summary after replay completes.
   - Reports message counts, active orders, elapsed time, and replay throughput.

---

### 🧩 Architectural Design Principles

- **Modular Design** – Each component has a clearly defined responsibility.
- **Separation of Concerns** – File I/O, protocol decoding, business logic, and statistics are implemented independently.
- **Extensibility** – New ITCH message types and processing modules can be added without changing the overall architecture.
- **Maintainability** – Components are loosely coupled, making the codebase easier to test, debug, and extend.
- **Performance-Oriented** – The pipeline minimizes unnecessary data copying while maintaining a simple and scalable processing flow.

## 📁 Project Structure

The project is organized into modular components, separating protocol definitions, core replay logic, utilities, documentation, and supporting resources. This structure improves maintainability, scalability, and ease of future development.

```text
hft-market-parser/
│
├── benchmarks/                # Performance benchmarks and benchmark results
├── build/                     # CMake build artifacts (generated)
├── data/
│   └── raw/                   # NASDAQ TotalView-ITCH datasets (not tracked)
│
├── docs/                      # Additional project documentation
├── images/                    # Architecture diagrams and README assets
│
├── include/                   # Public header files
│   ├── byte_utils.h           # Endian conversion utilities
│   ├── itch_protocol.h        # NASDAQ ITCH protocol message definitions
│   ├── itch_reader.h          # Binary file reader interface
│   ├── itch_decoder.h         # ITCH message decoder interface
│   ├── order_book.h           # In-memory limit order book
│   ├── replay_engine.h        # Replay engine interface
│   └── statistics.h           # Replay statistics data structures
│
├── legacy/                    # Archived prototype implementations
│
├── scripts/                   # Utility scripts and helper tools
│
├── src/
│   └── itch/
│       ├── main.cpp           # Application entry point
│       ├── itch_reader.cpp    # Binary dataset reader
│       ├── itch_decoder.cpp   # ITCH message decoding logic
│       └── replay_engine.cpp  # Replay pipeline implementation
│
├── tests/                     # Unit and integration tests (planned)
│
├── .gitignore
├── CMakeLists.txt             # CMake build configuration
├── LICENSE                    # MIT License
└── README.md                  # Project documentation
```

---

### 📌 Directory Responsibilities

| Directory | Purpose |
|-----------|---------|
| `include/` | Public headers defining interfaces, protocol structures, and utilities. |
| `src/` | Core implementation of the replay engine and protocol processing pipeline. |
| `data/` | Location for NASDAQ ITCH datasets used during replay (excluded from Git). |
| `benchmarks/` | Benchmark reports and future performance measurements. |
| `docs/` | Additional documentation and design notes. |
| `images/` | Diagrams, screenshots, and visual assets used in the README. |
| `scripts/` | Helper scripts for automation and future tooling. |
| `tests/` | Test suite for validating parser and replay engine correctness. |
| `legacy/` | Archived experimental code retained for reference. |

---

### 🧩 Design Philosophy

The repository follows a modular organization where each directory serves a single responsibility. This separation simplifies maintenance, encourages extensibility, and allows new protocol handlers, replay components, benchmarks, or testing modules to be integrated without affecting the overall project structure.

## 📊 Performance & Benchmark

The replay engine has been evaluated using a real **NASDAQ TotalView-ITCH 5.0** binary dataset. The benchmarks below represent the current implementation running in a **Linux (WSL)** development environment using the Modern C++20 replay pipeline.

> **Note:** These benchmarks reflect the current implementation and serve as a baseline for future optimizations. Planned improvements such as memory-mapped I/O (`mmap`), cache-aware data structures, and multi-threaded replay are expected to further improve throughput.

---

### 🖥️ Benchmark Environment

| Component | Specification |
|-----------|---------------|
| Language | C++20 |
| Build System | CMake |
| Compiler | GCC 13 |
| Operating System | Ubuntu (WSL) |
| Dataset | NASDAQ TotalView-ITCH 5.0 |
| Dataset Size | ~8.1 GB |

---

### 📈 Replay Benchmark Results

#### Development Benchmark

| Metric | Value |
|--------|------:|
| Messages Processed | 10,000,000 |
| Replay Time | 17.14 seconds |
| Throughput | 583,472 messages/sec |

---

#### Large-Scale Benchmark

| Metric | Value |
|--------|------:|
| Messages Processed | 100,000,000 |
| Replay Time | 543.49 seconds |
| Throughput | 183,997 messages/sec |

---

### 📊 Supported ITCH Message Statistics (100 Million Replay)

| Message Type | Count |
|-------------|------:|
| System Event (`S`) | 3 |
| Stock Directory (`R`) | 8,849 |
| Add Order (`A`) | 43,756,409 |
| Order Executed (`E`) | 2,136,661 |
| Order Cancel (`X`) | 1,432,796 |
| Unknown Messages | 52,665,282 |
| Active Orders Remaining | 42,304,824 |

---

### 🎯 Scalability

The replay engine has been successfully validated on datasets containing:

- **10 Million** market events
- **100 Million** market events
- **282+ Million** market events (Full NASDAQ trading-day dataset)

This demonstrates the ability to process large-scale binary market data while maintaining an in-memory limit order book throughout replay.

---

### 🚀 Future Performance Optimizations

The following enhancements are planned for future releases:

- Memory-mapped file I/O (`mmap`)
- Lock-free data structures
- Cache-aware memory layouts
- SIMD-assisted parsing
- Multi-threaded replay pipeline
- Detailed latency profiling
- Advanced performance benchmarking

## 🚀 Build & Usage

### 📋 Prerequisites

Ensure the following tools are installed on your system before building the project:

- **C++20 compatible compiler** (GCC 13+ or Clang 16+ recommended)
- **CMake 3.16+**
- **Git**

Verify your installation:

```bash
g++ --version
cmake --version
git --version
```

---

## 📥 Clone the Repository

```bash
git clone git@github.com:RajendharAre/hft-market-parser.git

cd hft-market-parser
```

---

## 🔨 Build the Project

Create an out-of-source build directory and compile using CMake.

```bash
mkdir build

cd build

cmake ..

make
```

After a successful build, the executable will be generated as:

```text
build/itch_reader
```

---

## 📂 Dataset Setup

Download the **NASDAQ TotalView-ITCH 5.0** dataset from the official NASDAQ website and place the binary file inside:

```text
data/raw/
```

Example:

```text
data/
└── raw/
    └── nasdaq_07302019.bin
```

> **Note:** Due to licensing restrictions and file size, the dataset is **not included** in this repository.

---

## ▶️ Running the Replay Engine

### Process the Entire Dataset

```bash
./build/itch_reader data/raw/nasdaq_07302019.bin
```

---

### Process a Limited Number of Messages

Replay only the first **10 million** messages:

```bash
./build/itch_reader data/raw/nasdaq_07302019.bin 10000000
```

Replay only the first **100 million** messages:

```bash
./build/itch_reader data/raw/nasdaq_07302019.bin 100000000
```

---

## 📤 Sample Output

```text
Processed 10000000 messages

========== Replay Finished ==========
Total Messages     : 10000000
System Events      : 2
Stock Directory    : 8849
Add Orders         : 3838374
Execute Orders     : 38708
Cancel Orders      : 635111
Active Orders      : 3814989
Unknown Messages   : 5478956
Elapsed Time       : 17.1388 sec
Throughput         : 583472 msg/sec
```

---

## 🧹 Clean Build

To remove all generated build files:

```bash
rm -rf build
```

Rebuild the project:

```bash
mkdir build

cd build

cmake ..

make
```
