# Chapter 3 File I/O

## 3.10 ファイル共有 File Sharing

あとの節 3.12 などのための前提知識.

TODO: 別途まとめたが、ここにも図を入れておく.

* プロセステーブルエントリの中の記述子の定義
* ファイルテーブルエントリとvノード/iノードの関係

これらは古く, Ken Thompton 1978 Unix の初期からあるが,
Linux においては vノードはなく, 汎用iノードを使っている.

### Q. 2つのプロセスが独立してファイルを開いているとき、どういう図ができるか.

## 3.12 不可分（アトミック）操作

### 例1. ログファイルの追記

独立した複数のプロセスが同一ファイルへの追記をすることについて.

...

ファイル末尾へのシークと書き込みが, ほかのプロセスに対して不可分であること.
=> UNIX システムではファイルフラグ `O_APPEND` を指定してファイルオープンをすると保証される.
=> pread/pwrite 関数が定義されている.

### 例2. 既存のファイルのオープン

関数 `open` にフラグ `O_CREAT` と `O_EXCL` を両方指定した場合について.

#### Q. open と creat の間で別プロセスが当該ファイルを作成するとどうなるか.

1. open
2. 別プロセスが同じファイルを creat
3. 別プロセスが同じファイルに書き込み
4. creat

結果として, 3. の内容がなくなる

### 不可分操作 atomic operation とは

複数の手順からなる操作で, その操作を行う場合, すべての手順が実行されるか,
どの手順も実行されないかのどちらかが保証されている必要がある.

## 3.13 
