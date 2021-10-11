# We want to swap the sex-column in the salary table
# Therefor we do an update-query on the salary table and set the sex-column.
# Now we enter the case-block, which looks at the sex-value for each altered row. 
# if it matches 'm' we will set it to 'f'. otherwise it will be set to 'm'.

update salary set sex = case sex when 'm' then 'f' else 'm' end;