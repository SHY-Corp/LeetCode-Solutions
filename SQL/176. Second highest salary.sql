Write a SQL query to getEmployeeThe second highest salary in the table (Salary).

select DISTINCT Salary  as SecondHighestSalary from Employee order by Salary DESC limit 1 offset 1

select (select DISTINCT Salary from Employee order by Salary DESC limit 1 offset 1) as SecondHighestSalary
