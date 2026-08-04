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
