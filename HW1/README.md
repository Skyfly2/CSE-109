# Lehigh University CSE109 - Systems Software - Homework 1

## Instructions

The purpose of this assignment is to familiarize yourself with the homework submission process. Every homework and project assignment will be hosted in a repository located at:

```
https://gitlab.com/lehigh-cse-109/<assignment-name>
```

Most homeworks and labs will require you to write code that passes a number of tests to get full credit. For information on the testing framework refer to the documentation [here](https://docs.gitlab.com/ee/ci/).

The process of working on assignments will proceed as follows:

0. Create a group for your CSE 109 projects. Name it as your gitlab username + "-cse109". e.g. mine would be "cmontella-cse109". You'll only do this once. Make sure to set the group as private, and add my gitlab account, [cmontella](https://gitlab.com/cmontella), as a member to the project with "maintainer" access-level.  [Instructions](https://docs.gitlab.com/ee/user/group/)

1. Fork the relevant repository into your own namespace. [Instructions](https://docs.gitlab.com/ee/workflow/forking_workflow.html#creating-a-fork)

2. Set your forked repository visibility to private. [Instructions](https://docs.gitlab.com/ee/public_access/public_access.html#how-to-change-project-visibility)

3. Add my gitlab account, [cmontella](https://gitlab.com/cmontella), as a member to the project with "maintainer" access-level. [Instructions](https://docs.gitlab.com/ee/user/project/members/#add-a-user)

4. Clone your newly forked repository to your computer. Your repository should be hosted at 
```
https://gitlab.com/<your user name>-cse109/<assignment name>
```
You can use the following git command with the appropriate values substituted to customize it for you:
```
git clone https://gitlab.com/<your user name>-cse109/<assignment name>
```
[Instructions](https://docs.gitlab.com/ee/gitlab-basics/start-using-git.html#clone-a-repository) 

5. You'll notice that the project does not compile. This is indicated at [here](https://gitlab.com/lehigh-cse-109/homework-1/pipelines). This shows the history of commits and whether or not the project after that commit passed the build process. You can discover why any build is failing by clicking on it. You'll see the console output of the build process. Follow [this link](https://gitlab.com/lehigh-cse-109/homework-1/-/jobs/419793217) for one example. This will give you an idea as how to what you need to do to fix the code. Modify main.c so that it compiles. (It's a trivial fix, the point of the assignment isn't the fix, it's to make sure you understand the process of submitting homework).

6. Commit the changes you made locally to your gitlab repository. Follow the instructions [here](https://githowto.com/staging_and_committing) (read sections 6, 7 and 8) about staging and committing changes.

7. Check the status of your commit with the appropriate values substituted to customize it for you at: 
```
https://gitlab.com/<your user name>-cse109/<assignment name>/pipelines
```