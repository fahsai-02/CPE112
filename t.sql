SELECT reason AS `Most Common Cancellation Reason`, 
       SUM(ticket_price) AS `Highest Refund Amount`
FROM Bookings 
JOIN Tickets ON Bookings.bookingID = Tickets.bookingID
WHERE bookingStatus = 'canceled'
GROUP BY reason
ORDER BY SUM(ticket_price) DESC
LIMIT 1;
