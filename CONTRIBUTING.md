# Contributing to aegisCapsule

Thanks for contributing to aegisCapsule.

## Testing Changes

1. Open Windhawk and load `aegis-capsule.wh.cpp` via **Mods > Create / Install from file**.
2. Verify compilation succeeds cleanly under Windhawk's MinGW/Clang toolchain with the embedded `@compilerOptions`.
3. Keep `aegis-capsule.cpp` and `aegis-capsule.wh.cpp` synchronized, and verify Windhawk mod metadata conventions (`BOOL WhTool_ModInit()`, `@github`, `@license`).
