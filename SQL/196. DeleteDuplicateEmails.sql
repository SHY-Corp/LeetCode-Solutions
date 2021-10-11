# We want to delete duplicate entries and keep the one with the smallest Id
# Therefor we start with a delete query but instead of only doing
# delete from Person 
# we go ahead and enter person twice (after the from)
# now we specify which person to delete (e.g. delete p from Person p, Person q)
# and last but not least we filter Person p with having the same email as q and a gerater ID

delete p from Person p, Person q where p.Email = q.Email and p.Id > q.Id;