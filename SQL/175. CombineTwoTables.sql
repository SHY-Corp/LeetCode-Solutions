select FirstName, LastName, City, State /* Selected the columns */
from Person left outer join Address     /* Left Outer join means all the matched entries + all entries from table Person*/
on Person.PersonId=Address.PersonId;    /* Join condition */
