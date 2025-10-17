
#!/bin/bash

echo "Enter number:" 
read number

for ((iter = number; 1 <= iter; iter--)); do
   echo "$iter"
done

echo "Ready"
