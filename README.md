# CF-template
CodeForces Template \times

Coding Faster Template \sqrt{}

### 使用方法

1. 本地编译选项加上 -D OUUAN 不开启优化方便调试，提交时自动开启优化。

2. 支持若干宏，详见代码。

3. `read()` 支持变长参数，并支持所有能使用 cin 读入的类型，支持使用左闭右开迭代器读入数组。在不开启 FAST_IOSTREAM 时，整型，char，double 会使用更快速的读入方式（但 cin 由于不关同步会较慢）。单参数读入整型，char，double 时会返回读入的值。不加参数时会返回读入的 long long。

4. `write()` 支持所有能使用 cout 输出的类型。在不开启 FAST_IOSTREAM 时，整型，char，double 会使用更快速的输出方式（但 cout 由于不关同步会较慢）。如果开启 FAST_IOSTREAM ，请在输出浮点数时自行设置精度。`wtb()`：输出并换行，支持使用左闭右开迭代器输出数组；`wts()`：输出并空格，支持使用左闭右开迭代器输出数组；`wte()`：输出并结束程序。wtb、wts、wte 均支持变长参数，输出时参数之间用空格分隔。

5. `up(x, y)`：将 x 设置为 `max(x, y)`，若 x 发生改变返回 `true`，否则返回 `false`。

   `dn(x, y)`：同 up，设置为 min。

6. [segmentTree](https://github.com/ouuan/segmentTree)

7. [maxFlow](https://github.com/ouuan/maxFlow)

8. [customHash](https://codeforces.com/blog/entry/62393)

### 压缩方式

1. 将 `(?<=[(){}<>,;.=&\|!+\-*/%:?]) | (?=[(){}<>,;.=&\|!+\-*/%:?])|  |	|^ | $|` 替换为空。
2. 将 `(^[^#\n]*$)\n(?=^[^#\n]*$)` 替换为 `\1`。
3. ~~将 `(^.{80,}?\b)(?!\n)` 替换为 `\1\n`。（多次替换直到全部替换完成）~~
4. ~~再次进行第一步。~~
5. 手动把 main 函数部分换成可读版。
6. ~~编译一下，手动处理引号内换行等问题。~~

（现在的方式如肉眼所见）