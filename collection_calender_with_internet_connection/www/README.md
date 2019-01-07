# Collection Calendar Homepage
The application has /plaintext and /json as an API option
  
| circle_id        | circle_description           |  
| ------------- |-------------|  
    |1  |1  |
    |2  |1a |
    |3	|1b |
    |4	|2  |
    |5  |3  |  
    |6  |4  | 
    |7  |5  |
    |8  |6  |
    |9	|7  |
    |10 |8  |  
    |11	|9  |  
Example:  If you live in circle 3 you circle id is 5.  
## How to use /plaintext
Request URL: https://www.collectioncalendar.christianpetri.ch/plaintext/?circle_id=6  
Request Method: GET  

Respondse: 100100

The first number is always 1 which is followed by 5 numbers which represent a boolean

1 = true, 0 = false // 1 = led is ON , 0 = led is OFF

100100 --> 
[1][0][0][1][0][0] 
[1] ["Grüngut"] ["Karton"] ["Kehricht und Sperrgut"] ["Metall"] ["Papier"]  
The first number represents nothing, it is a placeholder to start the sequence

The second number represents green waste

The third number represents cardboard

The fourth number represents general waste and "bulky goods"

The fifth number represents metal waste

The sixth number represents paper waste

isGreenRecyclingToday = false --> Light is off  
isCardboardRecyclingToday = flase --> Light is off  
isGeneralWasteRecyclingToday = true --> Light is on  
and so on
##How to use json
Request URL: https://www.collectioncalendar.christianpetri.ch/json/?circle_id=6  
Request Method: GET

Respondse: [{"collection_date":"2018-09-12","garbage_type_id":"2","garbage_type_description":"Karton"}]

### Connection string for you Database
not yet implemented:  
place the .ini file into your root folder (one below the public folder) and fill in your credentials.