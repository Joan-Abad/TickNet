# TickNet Coding Standard

This document defines the coding rules and architectural principles for TickNet.

The goal is to maintain a clean, consistent, and professional codebase comparable to production-quality systems.

---

## 1. Language and Build

- C++ standard: **C++20**
- Build system: **CMake**
- Platforms: **Windows + Linux**
- Configurations:
  - Debug
  - Release

# TickNet Coding Standard

This document defines the coding rules and architectural principles for TickNet.

The goal is to maintain a clean, consistent, and professional codebase comparable to production-quality systems, combining **Unreal Engine-style conventions** with modern C++ practices.

---

## 1. General Principles

- Prefer **clarity over cleverness**
- Write code that is easy to debug and reason about
- Avoid hidden behavior and implicit side effects
- Keep systems **modular and layered**
- Maintain strict consistency across the codebase

---

## 2. Language and Build

- C++ standard: **C++20**
- Build system: **CMake**
- Platforms: **Windows + Linux**

### Configurations
- Debug
- Release

### Compiler Rules

- Warnings are treated as **errors**

**MSVC**
- `/W4 /WX`

**GCC/Clang**
- `-Wall -Wextra -Wpedantic -Werror`

---

## 3. Naming Conventions

TickNet follows a naming style inspired by Unreal Engine, adapted for a standalone systems library.

### Types

- Use **PascalCase with `F` prefix**

```cpp
FPacketHeader
FUdpSocket
FConnection
FSequenceBuffer````

## 4. Additional Naming Rules

## ENUMS

Enums must use `enum class` and have an `E` prefix for the type. Values use PascalCase and must be descriptive. Avoid unscoped enums unless strictly necessary.



```cpp
enum class EConnectionState : uint8_t
{
    Disconnected,
    Connecting,
    Connected
};```

## Interfaces

Interface/abstract types must use the I prefix and contain only virtual behavior.

class IPacketHandler;

## Templates

Template types may use the T prefix, but only for generic/template classes.

## Aliases

Type aliases should use using and follow PascalCase with an F prefix when representing a conceptual type.

using FPacketSequence = uint16;
using FPacketMask = uint32;

Avoid prefix abuse. Only use:

F → structs/classes
E → enums
I → interfaces
T → templates (only when generic)


