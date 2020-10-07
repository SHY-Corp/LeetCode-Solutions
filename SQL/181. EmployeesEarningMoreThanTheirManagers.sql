Select a.Name as Employee                /* Selecting Column and renaming it */
from Employee as a join employee as b    /* Join with self by using different names */
on a.ManagerId=b.Id                      /* Join condition */
and a.Salary>b.Salary;                   /* Condition for record selection from joined table */
