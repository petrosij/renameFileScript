remote ---> local 
git remote add <remote name> <URL> // remote name for example 
git remote show  <remote name>
git remote -v // show all remotes
git remote -v show -n <remote name>
git fetch <remote name> <branch name>
git merge <remote name>/<branch name> // после этого git pull будет сливать локальную ветку с удаленной 
git checkout -b <branch name> <remote name>/<branch name>

local ---> remote
git push -u <remote name> <branch name>

git STASH
git stash save "message" // save changes but not commit them (to change to another branch)
git stash save -u "message" // include untracked files
git stash save -p "message" // patch (you choose witch files to add to stash)
git stash list // list all stashes
git stash show stash@{index of stash} // show info about saved changes in specified stash
git stash apply stash@{index of stash} // apply saved changes
git stash pop stash@{index of stash} // apply stash and delete stash from the stash list
git stash drop stash@{index of stash} // delete stash from stash list (you do that after "apply" command)

TODO
Не переименовывает если такой файл существует
    Нужно переименовывать в 2 этапа 
    1 С созданием временной папки
    2 С созданием временного названия файла
Добавить верхнюю вариант работы без верхней границы
Убрать последнюю точку для последней цифры
Добавить обработку неправильного именги файла - 2._name.txt кидает исключение

