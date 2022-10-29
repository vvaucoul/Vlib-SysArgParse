# Vlib-SysArgParse
Arguments Parser library for C programs.

Tired to parse each argument by manually ?<br>
Use the **SysArgParse** library to make your life easier.<br>

Future updates will be added soon.

## Usage

- Clone Repository
```bash
git clone https://github.com/vvaucoul/Vlib-SysArgParse && cd Vlib-SysArgParse
```

- Compilation
```bash
make
```

- Installation
```bash
sudo make install
```

- Uninstall
```bash
sudo make uninstall
```

- Compilation
```bash
gcc 'program.c' -l -sys-arg-pars
```

## Functions

```C
int sys_arg_start(int argc, const char **argv);
void sys_arg_end(void);
const char *sys_arg_get_executable_name(void);
const sys_arg_t *sys_arg_next(void);
const sys_arg_t *sys_arg_prev(void);
const sys_arg_t *sys_arg_set(const sys_index index);
const sys_arg_t *sys_arg_get(void);
sys_index sys_arg_index(void);
sys_index sys_arg_count(void);
```

> **sys_index**: **unsigned int**

## Example

![Animation](https://user-images.githubusercontent.com/66129673/198832264-e1ac074f-d0f3-40de-8be6-d5199c38cc14.gif)
