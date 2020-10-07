Select a.Name as Employee 
from Employee as a join employee as b
on a.ManagerId=b.Id
and a.Salary>b.Salary;