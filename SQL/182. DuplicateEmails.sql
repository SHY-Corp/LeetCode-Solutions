/*
	Since we need to filter all the Emails which has appeared more than once, we can use the count function which is an aggregate function thus, we
	use Group by. 
	Finally, we display Emails whose count is greater than 1.
*/

select Email from Person group by Email having count(Email)>1;