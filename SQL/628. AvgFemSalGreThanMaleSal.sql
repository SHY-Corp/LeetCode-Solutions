
/* SQL Program to retrieve the department numbers which have female average salary
    greater than male average salary of the same department.*/

select dno as Dept_No   /* Selecting department number */
from Employee as E1
where E1.gen = 'F'      /* Selecting female employees */
group by dno
having avg(salary) > (select avg(salary) 
                      from Employee as E2
                      where E2.gen = 'M'    /* Selecting male employees */
                      and E2.dno = E1.dno) 
