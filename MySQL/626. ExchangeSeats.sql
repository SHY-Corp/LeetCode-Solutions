#This code gives back every entry from the "seat"-Table but switches the ids in pairs (e.g. 1 <-> 2, 3 <-> 4, ...). The last one (if without a partner) stays itself.

select 
    (case
        when mod(id, 2) != 0 and id = counts then id
        when mod(id, 2) != 0 and id != counts then id+1
        else id - 1
    end) as id,
    student
from
    seat,
    (select 
        count(*) as counts
     from
        seat)
        as seatCount
order by
    id asc;