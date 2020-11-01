/* Solution to Problem 176. Second Highest Salary

Link to Problem: https://leetcode.com/problems/second-highest-salary/

Question: Write a SQL query to get the second highest salary from the Employee table.

Solution Logic:

A sub query is first used to select the max salary from the Employee table.

Considering all other salaries in the table 
except the max salary obtained in the subquery,
we then take the max salary from these remaining salaries, 
which becomes the second highest salary.

A subquery was used to select the max salary, since group functions can't be used in WHERE clause.
 */
select max(Salary) SecondHighestSalary from Employee        /* Selecting max salary from remaining salaries, renaming the column as SecondHighestSalary */
where Salary != (select max(Salary) from Employee);         /* WHERE clause used to reject only the highest salary in the table. */