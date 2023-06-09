
# Basic PDF Parsing with C++

This is is an example of PDF parsing using the **Poppler** library for **C++**.

---

## Explanation

**File Setup**

    % tree
    .
    ├── CMakeLists.txt
    ├── build.sh
    ├── include
    │   └── pdf
    │       └── PDF.h
    └── src
        └── pdf
            ├── PDF.cc
            └── example.cc

&nbsp;

**Running the Example:**

In the CMakeLists.txt, add the correct paths for the **Poppler** `include` & `lib` directories. This might look something like

    31  /opt/homebrew/Cellar/poppler/23.05.0/lib

and

    35  /opt/homebrew/Cellar/poppler/23.05.0/include

respectively, (*note*: the above example uses my **Homebrew** paths). Next, move a PDF file into the `src/pdf` directory and update `example.cc` with the filename. This should now look something like

    9   Document doc("../src/pdf/FileName.pdf");

or a different file path of choice, relative to the build location of the executable. Next, run

    % ./build.sh

from the project directory and a `build` directory will be created with the `example` executable inside. Run (still from the project directory)

    % ./build/example

to print the chosen PDF in the terminal.

&nbsp;

**PDF Namespace & Document Class:**

&emsp;This example uses a `PDF` namespace containing a `Document` class. `PDF::Document` objects represent a PDF file and include basic functionality, such as reading the entire file, reading individual pages, and creating `Document::Page` objects, which can also be read by `Document` objects. The `PDF::operator <<` has been overloaded (for both `PDF::Document` and `Document::Page`) to allow for easier interactions with `std::ostream` objects.

New features can be added directly into these files, such as

- free functions within the namespace
- class methods
- overloaded operators
- an iterator & range-based for loop support

---

## Versions Used

**C++:**

- *C++14* or higher to use **Poppler**
- *C++17* to use `std::filesystem` (can be implemented without this)

**Poppler:**

- *23.05.0*

---

## References & Further Reading

**Poppler:**

- [Download](https://poppler.freedesktop.org/)

- [Documentation](https://poppler.freedesktop.org/api/cpp/index.html)

**Homebrew:**

- [Website](https://brew.sh/)

**CMake Help:**

- [Examples on GitHub](https://github.com/ttroy50/cmake-examples/tree/master/01-basic)

**Style Guide:**

- [Pitchfork](https://api.csswg.org/bikeshed/?force=1&url=https://raw.githubusercontent.com/vector-of-bool/pitchfork/develop/data/spec.bs)

---
