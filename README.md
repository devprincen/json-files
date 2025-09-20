<<<<<<< HEAD
# json-files
A simple JSON parsing and handling utility in C language using cJSON library.   Contains basic read/write functions for JSON files (json_io.c/h) and cJSON implementation.
=======
# JSON I/O Helper for C Projects

This library provides simple functions to **load** and **save** JSON files using [cJSON](https://github.com/DaveGamble/cJSON).  
It makes it easy to reuse across multiple projects.

---

## 📂 Setup

1. Copy these files into your project folder:
   - `json_io.h`  
   - `json_io.c`  
   - `cJSON.h`  
   - `cJSON.c`  

2. In your C code, include the header:

   ```c
   #include "json_io.h"
   ```

---

## 🔨 Compilation

Compile your project with:

```bash
gcc main.c json_io.c cJSON.c -o myprogram
```

Replace `myprogram` with any name you want for your executable.

---

## 📌 Example

```c
#include <stdio.h>
#include "cJSON.h"
#include "json_io.h"

int main() {
    // Create JSON
    cJSON *obj = cJSON_CreateObject();
    cJSON_AddStringToObject(obj, "name", "Prince");
    cJSON_AddNumberToObject(obj, "score", 95);

    // Save to file
    json_save("data.json", obj);
    cJSON_Delete(obj);

    // Load back
    cJSON *loaded = json_load("data.json");
    if (loaded) {
        printf("Loaded JSON:\n%s\n", cJSON_Print(loaded));
        cJSON_Delete(loaded);
    }

    return 0;
}
```

---

✅ Now you can reuse `json_io` in all your projects.
>>>>>>> 95b9872 (A simple JSON files parsing and handling utility in C language using cJSON library)
