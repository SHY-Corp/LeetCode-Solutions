# We want to select all Customers who never ordered
# Therefor we select them
# and then join onto the orders.
# Afterwards we take out all who have an orderId associated.
select Name as 'Customers' from Customers c left join Orders o on o.CustomerId = c.Id where o.Id is null;