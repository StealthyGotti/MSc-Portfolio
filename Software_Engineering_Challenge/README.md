# Software Engineering Projects

This repository highlights a multidisciplinary approach combining advanced software architectural design with rigorous quality assurance and testing methodologies for high-performance contexts.

---

## 🚦 Breaking Red: Smart Traffic Management System

**Breaking Red** is a comprehensive software architecture designed to reduce urban commuting impact through real-time traffic light optimization and data-driven infrastructure analysis.

### 🎯 Project Goals
The system implements two strategic action types:
* **Type 1 (Real-Time)**: Dynamic modification of traffic light durations based on live sensor data to balance intersection flows.
* **Type 2 (Optimization)**: Identification of long-term improvements (one-way roads, public transport schedules) through historical pattern analysis.

### 🏗️ Architectural Design
The solution follows a **Microservice Architecture** managed via **Docker and Kubernetes** for high scalability and technology heterogeneity:
* **Main System**: Central logic responsible for processing sensor data, generating optimization suggestions, logging actions, and producing reports.
* **Local System**: Edge systems installed at each intersection to ensure consistency between traffic lights and execute real-time adjustments.
* **Event-Driven Backbone**: Communication handled via **Apache Kafka** and **ZooKeeper** to manage asynchronous data streams.

### 🛠️ Tech Stack & Key Components
* **Orchestration**: Kubernetes and Docker for automated deployment and scaling.
* **Data Management**: MySQL (Persistence), Redis (In-memory analysis), and Neo4j (Graph-based street mapping).
* **Communication**: Apache Kafka as a distributed, fault-tolerant message bus.
* **Security**: JSON Web Token (JWT) standard for secure portal access.

**Team**: Ettore Cirillo, Mattia Gotti, Angelo Notarnicola.
*Developed for the "Software Engineering for HPC" course at Politecnico di Milano.*

---

## 🧪 Black-Box Software Testing (Grayscale Conversion)

This project focuses on the **quality assurance and robustness analysis** of a pre-compiled image processing library. The goal was to identify bugs and edge-case failures in a `convertToGrayscale` function without access to its source code.

🔗 **[Project Repository & Source Code](https://github.com/notarnic/CirilloGottiNotarnicola_DevOps_first_part)**

### 🎯 Project Overview
We adopted a **black-box but behavior-aware** strategy. Since the source code was unavailable (linked as a static library), we designed a comprehensive test suite to infer internal logic and detect incorrect behaviors through empirical analysis.

### 🧠 Testing Strategy
Our goal was to achieve "minimum effort, maximum coverage," a key principle in High-Performance Computing (HPC), by focusing on:
* **Functional Correctness**: Validating arithmetic results for each grayscale method.
* **Robustness**: Handling invalid/corrupted inputs (negative RGB, undefined enums) without crashing.
* **Structural Integrity**: Ensuring matrix shape preservation and loop consistency.
* **Edge Cases**: Stress-testing with black, gray, and extreme color pixels.

**Tech Stack**: C++17, Google Test (GTest), CMake.