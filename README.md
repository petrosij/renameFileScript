remote ---> local 
git remote add <remote name> <URL> // remote name for example 
git remote show  <remote name>
git remote -v // show all remotes
git fetch <remote name> <branch name>
git merge <remote name>/<branch name> // после этого git pull будет сливать локальную ветку с удаленной 
git checkout -b <branch name> <remote name>/<branch name>

local ---> remote
git push -u <remote name> <branch name>

