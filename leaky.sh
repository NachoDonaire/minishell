#! /bin/bash
while true
do
	leaks -atExit -- ./minishell
done
