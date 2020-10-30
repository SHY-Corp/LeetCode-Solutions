# SQL query to display the records with three or more rows with consecutive id's, and the number of people is greater than or equal to 100 for each.
# Returned table is ordered by visit_date in ascending Order

select id, visit_date,people from (select
*
,lead(id,1) over(order by visit_date asc) as id1
,lead(id,2) over(order by visit_date asc) as id2
,lag(id,1) over(order by visit_date asc) as id3
,lag(id,2) over(order by visit_date asc) as id4
from stadium
where people>=100) a where
(id1-id =1 and id2-id1=1)
or (id-id3 =1 and id3-id4=1)
or (id-id3 =1 and id1-id=1)
or (id-id3 =1 and id1-id=1)
