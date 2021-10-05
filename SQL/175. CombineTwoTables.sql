# The query selects Names and joins the Address table to the Person table
select p.Firstname, p.LastName, a.City, a.State from Person p left join Address a on p.PersonId = a.PersonId;
