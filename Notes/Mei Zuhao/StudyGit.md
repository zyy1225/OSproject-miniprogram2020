# 创建仓库命令

$ git init
初始化仓库

$ git clone
拷贝一份远程仓库，即下载一个项目

$ git status
查看仓库的状态

$ git add [file1] [file2] ...
添加一个或多个文件到暂存区
$ git add [dir]
添加指定目录到暂存区，包括子目录
$ git add .
添加当前目录下的所有文件到暂存区

$ git branch
显示分支一览表

$ git branch feature-A
创建feature-A分支

$ git checkout feature-A
将当前分支切换为feature-A 分支

# 文件操作

$ mkdir dirName
创建一个名为dirName的文件夹

$ mkdir -p dirName/dirSub
在dirName目录下创建dirSub目录，-p代表如果dirName不存在，则新建一个