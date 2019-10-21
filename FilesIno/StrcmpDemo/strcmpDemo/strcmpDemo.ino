char nums[] = "0123456789."; // The characters we will check against

/* Tried also these, same results
      char nums[12] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '\0'};
      char nums[] = "456789.0123";
*/

void setup() {
  Serial.begin(9600);
  Serial.println("Write a single character"); Serial.println(" ");
}

void loop() {
  if (Serial.available() > 0) {
    char text = Serial.read(); // Read a single char from serial
    Serial.print("Character provided is: "); Serial.println(text);
    char c = parseChar(text); // Evaluate the char
    Serial.print("Character returned is: "); Serial.println (c);
    if (strcmp(c, text) == 0) { // Check if the returned char is the same
      Serial.print("      CORRECT character returned");
    } else {
      Serial.print("      WRONG character returned");
    }
    Serial.println(" ");
  }
}

char parseChar(char c) {
  int comp = 0;
  Serial.println("----- parseChar() START-----");
  Serial.print("  Parameter 'c' is: "); Serial.println(c);
  for (int i = 0; i < sizeof(nums) ; i++) { // Check the values of the array one by one
    comp = (c - nums[i]);
    //comp = strcmp(c, nums[i]); // Compare the chars
    Serial.print("  Compare to nums["); Serial.print(i); Serial.print("] = "); Serial.print(nums[i]); Serial.print(" --> Result: "); Serial.println(comp);

    /* If the check matches, return the character at that index.
       For simplicity, it just returns the matching char of the array,
       that should be the same as the one sent in to the function.
    */
    if (comp == 0) {
      Serial.println("----- parseChar() END (found) -----");
      return nums[i];
    }
  }
  Serial.println("----- parseChar() END (not found)-----");
  return 0;
}
