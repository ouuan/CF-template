# CF-template

[![Compile Test](https://github.com/ouuan/CF-template/workflows/Compile%20Test/badge.svg)](https://github.com/ouuan/CF-template/actions)

CodeForces Template \times

Coding Faster Template \sqrt{}

### 使用方法

1. 本地编译选项加上 -D OUUAN 不开启优化方便调试，提交时自动开启优化。

2. 支持若干宏，详见代码。

3. 从 tourist 的模板里 copy 的 `debug` 。

4. `read()` 支持变长参数，并支持所有能使用 cin 读入的类型，支持使用左闭右开迭代器读入数组。在不开启 FAST_IOSTREAM 时，整型，char，double 会使用更快速的读入方式（但 cin 由于不关同步会较慢）。单参数读入整型，char，double 时会返回读入的值。不加参数时会返回读入的 long long。

5. `write()` 支持所有能使用 cout 输出的类型。在不开启 FAST_IOSTREAM 时，整型，char，double 会使用更快速的输出方式（但 cout 由于不关同步会较慢）。如果开启 FAST_IOSTREAM ，请在输出浮点数时自行设置精度。`wtb()`：输出并换行，支持使用左闭右开迭代器输出数组；`wts()`：输出并空格，支持使用左闭右开迭代器输出数组；`wte()`：输出并结束程序。wtb、wts、wte 均支持变长参数，输出时参数之间用空格分隔。

6. `up(x, y)`：将 x 设置为 `max(x, y)`，若 x 发生改变返回 `true`，否则返回 `false`。

   `dn(x, y)`：同 up，设置为 min。

   `inRange(x, l, r)`: 判断 x 是否在 [l, r] 内。

   `max` 和 `min` 支持参数类型不同。

   `madd(x, y, mod)` 和 `mmul(x, y, mod)`，将 x 加/乘上 y 对 mod 取模然后返回 x 的引用。

   `modadd(x, y, mod)` 返回 `(x + y) % mod` 的结果，需要保证 x 和 y 都在 [0, mod) 内，速度较快。

### 压缩方式

1. 将 `(?<=[(){}<>,;.=&\|!+\-*/%:?]) | (?=[(){}<>,;.=&\|!+\-*/%:?])|  |	|^ | $` 替换为空。
2. 将 `(^[^#\n]*$)\n(?=^[^#\n]*$)` 替换为 `\1`。
3. ~~将 `(^.{80,}?\b)(?!\n)` 替换为 `\1\n`。（多次替换直到全部替换完成）~~
4. ~~再次进行第一步。~~
5. 手动把 main 函数部分换成可读版。
6. ~~编译一下，手动处理引号内换行等问题。~~

（现在的方式如肉眼所见）