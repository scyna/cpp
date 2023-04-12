curl --location --request POST 'http://localhost:8080/example/hello' \
--header 'Client-Id: example_test' \
--header 'Client-Secret: 123456' \
--header 'Content-Type: application/json' \
--data-raw '{
    "Name": "Alice"
}'
