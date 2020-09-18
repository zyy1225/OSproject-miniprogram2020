# git入门

<p align="right">--by 许茂泽</p>

## 基本命令

```shell
git init #初始化仓库

git add #将文件加入暂存区

git commit #将暂存区文件提交入版本库

git status #查看当前仓库状态

git diff #比较工作区中的该文件与暂存区或版本库最后一次提交中的区别

git log #查看仓库提交历史

git config --global alias.l "log --color --graph --all --pretty=format:'%Cred%h%Creset -%C(yellow)%d%Creset %s%Creset %Cgreen(%cd) %C(bold blue)<%an>%Creset' --abbrev-commit --date='format:%Y-   %m-%d %H:%M:%S'" #配置git命令的别名并设置输出格式

git checkout -- <file>  #从暂存区覆盖工作区，如果暂存区为空则从版本库恢复

git reset --hard HEAD^ #回到上一个提交版本，并使得工作区与暂存区与版本库中保持一致

git reset --hard HEAD #回到最新提交版本，其实就是重置工作区和暂存区

git reset HEAD #回到最新提交版本，但不重置工作区

#如果切换前工作区和暂存区是干净的，切换后工作区会换到新分支的内容
git checkout <branch> #切换分支

git checkout -b <branch> #创建并切换分支

git merge <branch> #把当前所在分支与<branch>分支合并

git branch -d <branch> #删除分支

#如果当前分支所做的修改没有提交的话，切换到其他分支仍能看到刚才的修改
git stash #需要新开分支，但暂时不想提交，保存当前工作

git stash pop #恢复原来工作

git clone <url> #把远程仓库下载到本地，此仓库默认为origin

git remote add upstream/origin <url> #添加远程仓库地址

git remote #查看本地添加的远程仓库

git fetch <远程主机名> <分支名> #拉取远程分支，但不合并

git pull <远程主机> <远程分支>:<本地分支> #拉取并合并，若合并到当前分支则最后一项可省

git push <远程主机> <本地分支>:<远程分支> #推送到远程分支，若分支名相同则最后一项可省，对应远程分支若不存在则会新建
```

## 概念

1. **工作区**

当前所在的工作目录

2. **暂存区**

已经add的文件，但还未最终加入版本库中

3. **版本库**

已经commit的文件，表示仓库中的版本

4. **远程仓库**

托管在云端的版本库

5. **GitHub协作模型**

![github_work_model](./github_work_model.png)

HEAD 指向当前所在分支

origin 自己远程仓库在本地的指针，在本地是无法更改的（即使可以切换过去，也无法通过commit等使它前移），也不会自动与远程仓库同步，需要fetch、pull等命令进行更新

upstream 别人远程（原始）仓库在本地的指针，同origin
