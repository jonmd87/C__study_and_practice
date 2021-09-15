#!bin/bash

echo ""
echo "CHECKS INCLUDES"
norminette ./includes/*h
echo ""
echo "CHECK SRCS"
norminette ./srcs/*c

