# CF-template
template to code faster for CP

1. 本地编译选项加上 -D OUUAN 不开启优化方便调试，提交时自动开启优化。

2. 支持若干宏，详见代码。

3. `read()` 支持变长参数，并支持所有能使用 cin 读入的类型。在不开启 USE_IOSTREAM 时，整型，char，double，char* 会使用更快速的读入方式（但 cin 由于不关同步会较慢）。单参数读入整型，char，double 时会返回读入的值。不加参数时会返回读入的 long long。

4. `write()` 支持所有能使用 cout 输出的类型。在不开启 USE_IOSTREAM 时，整型，char，double，char* 会使用更快速的输出方式（但 cout 由于不关同步会较慢）。`wtb()`：输出并换行。`wts()`：输出并空格。wtb 和 wts 均支持变长参数，参数之间用空格分隔。

5. `up(x, y)`：将 x 设置为 `max(x, y)`，若 x 发生改变返回 `true`，否则返回 `false`。

   `dn(x, y)`：同 up，设置为 min。