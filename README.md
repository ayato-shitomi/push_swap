# Push_swap

## 概要
このプロジェクトはCで数字のソートを行います。
2つの領域（`stack_a`と`stack_b`）を用意して入力された数字を２つの領域へ入れたり出したりしながら、ソートします。


## 開発環境と実行

### 環境
```
ubuntu@ubuntuv_10.0.2.15~ via 😈️ 2GiB/23GiB | 0B/1GiB 
 └─>😀️ ~    uname -a && gcc --version 

Linux ubuntuv 5.13.0-52-generic #59~20.04.1-Ubuntu SMP Thu Jun 16 21:21:28 UTC 2022 x86_64 x86_64 x86_64 GNU/Linux
gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0

Copyright (C) 2019 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
```

### 実行方法

```bash
> make
> ./push_swap <ソートしたい数字>
```

### 入力と出力（実行例）

実行例から、プログラムがどのように動作するのかを見てみましょう！

入力は以下のように引数に整数をスペース区切りで入力してください。

```
ubuntu@ubuntuv_10.0.2.15~/42Tokyo/Lv2/push_swap_intra via 😈️ 2GiB/23GiB | 0B/1GiB 
 └─>😀️ ~  ./push_swap 8 7 3 4 1
pb
rra
sa
ra
pa
ra
```

出力にはこのような意味があります。

|命令|意味|操作|
|----|----|----|
|sa|swap a|`stack_a`の最初の２つの要素を入れ替える。|
|sb|swap b|`stack_b`の最初の２つの要素を入れ替える。|
|ss|sa and sb|`sa`と`sb`を同時にする。|
|pa|push a|`stack_b`の最初の要素を取って、`stack_a`の最初に入れる|
|pb|push b|`stack_a`の最初の要素を取って、`stack_b`の最初に入れる|
|ra|rotate a|１度に`stack_a`の最初の要素を最後にローテーションする。|
|rb|rotate b|１度に`stack_b`の最初の要素を最後にローテーションする。|
|rr|ra and rb|`ra`と`rb`を同時にする。|
|rra|reverse rotate a|１度に`stack_a`の最後の要素を最初にローテーションする。|
|rrb|reverse rotate b|１度に`stack_b`の最後の要素を最初にローテーションする。|
|rrr|rra and rrb|`rra`と`rrb`を同時にする。|

先程の例でスタックの内部がどのようになっているか可視化して追ってみましょう。

`最初`：引数は一度`stack_a`に全て入ります。
```
stack_a	:	8 7 3 4 1
stack_b	:	
```
`pb`：`stack_a`の最初の要素（`8`）を`stack_b`の最初に入れました。
```
stack_a	:	7 3 4 1
stack_b	:	8
```
`rra`：`stack_a`の一番後ろの要素（`1`）を前にローテーションしました。
```
stack_a	:	1 7 3 4
stack_b	:	8
```
`sa`：`stack_a`の最初の２つの要素（`1`と`7`)の順番を入れ替えました。
```
stack_a	:	7 1 3 4
stack_b	:	8
```
`ra`：`stack_a`の最初の要素（`7`）を一番後ろに持っていきました。
```
stack_a	:	1 3 4 7
stack_b	:	8
```
`pa`：`stack_b`の最初の要素（`8`）を`stack_a`の一番前に持っていきました。
```
stack_a	:	8 1 3 4 7
stack_b	:	
```
`ra`：`stack_a`の最初の要素（`8`）を一番後ろに持っていきました。
```
stack_a	:	1 3 4 7 8
stack_b	:	
```
ここでソートができているので、出力されます。

## 仕様とエラーケース

> 引数に指定した数字の個数が未満１の場合には`Error\n`が出力されます。

## 技術的解説

### ファイル階層

ファイル階層は以下のとおりです。

```
/home/ubuntu/42Tokyo/Lv2/push_swap
|--.git
|
|--includes
|  |--push_swap.h
|
|--Makefile
|--README.md
|
|--srcs
|  |--42Tokyo.code-workspace
|  |--add_state.c
|  |--align_stacks.c
|  |--bruteforce.c
|  |--bruteforce_pick_check.c
|  |--free_something.c
|  |--ft_bzero.c
|  |--ft_calloc.c
|  |--ft_memset.c
|  |--ft_putstr_fd.c
|  |--ft_strdup.c
|  |--ft_strlen.c
|  |--ft_strncmp.c
|  |--instructions.c
|  |--instructions_utils.c
|  |--less_mvt.c
|  |--main.c
|  |--movement.c
|  |--new_empty_state.c
|  |--pushswap_utils.c
|  |--resolve.c
|  |--resolve_utils.c
|  |--rotate.c
|  |--stack.c
|  |--stacks_utils.c
|  |--stack_utils.c
|  |--utils.c
```

### アルゴリズムに関して

アルゴリズム自体はあまり賢くありません。

> サイズが５以下はブルートフォース形式でソートします。

> サイズ５が以上の場合に関しては、最初を動かせばいいか最後を動かせばいいかを判定します。
その上で`stack_a`の最初の２つの要素の大小比べて`stack_b`に入れれるべきかを判定します。その後、`stack_a`から`stack_b`へ戻しソートできているかどうかを判定。この一連の流れを繰り返します。

一部ソートできないケースがあったので、そこを最後の`print_some`という関数で強制的に出力します。

### 使用関数

使用可能な関数は以下のみです。
> read, write, malloc, free, exit

### Makefile

Makeコマンドには以下のオプションがあります。

```
make		通常のコンパイル
make clean	実行ファイルの削除
make fclean	実行ファイルの削除（オブジェクトファイルが無いため）
make re		再コンパイル
make test	簡易的なテストケースの実行
```

いずれのコンパイル方式を採用しても、`-g3 -fsanitize=address -fsanitize=leak`が動作します。
メモリーリーク等がある場合には必ずエラーが出力されます。
