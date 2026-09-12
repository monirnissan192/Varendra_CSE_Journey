from PIL import Image

def hide_message(image_path, message, output_path):
    # Open the image and get pixel data
    img = Image.open(image_path).convert('RGB')
    pixels = img.load()

    # Convert the secret message to binary. 
    # We also add a secret "delimiter" (1111111111111110) at the end 
    # so the decoder knows exactly when the message stops.
    binary_msg = ''.join([format(ord(c), '08b') for c in message]) + '1111111111111110'
    
    data_index = 0
    
    # Loop through every pixel
    for y in range(img.height):
        for x in range(img.width):
            r, g, b = pixels[x, y]
            
            # If we still have message bits to hide...
            if data_index < len(binary_msg):
                # Modify the Least Significant Bit of the RED channel only
                # (r & ~1) clears the last bit, then we add our secret bit
                r = (r & ~1) | int(binary_msg[data_index])
                data_index += 1
            
            # Update the pixel
            pixels[x, y] = (r, g, b)
            
            # Once all bits are hidden, save the image
            if data_index >= len(binary_msg):
                # MUST save as PNG. JPG compresses data and destroys the secret bits!
                img.save(output_path)
                print("Message hidden successfully inside:", output_path)
                return

def reveal_message(image_path):
    img = Image.open(image_path).convert('RGB')
    pixels = img.load()
    
    binary_msg = ""
    
    # Read every pixel's RED channel
    for y in range(img.height):
        for x in range(img.width):
            r, g, b = pixels[x, y]
            # Extract only the last bit (LSB)
            binary_msg += str(r & 1)
    
    # Cut off all the extra data using our delimiter
    binary_msg = binary_msg.split('1111111111111110')[0]
    
    # Convert the binary string back into readable text characters
    message = "".join([chr(int(binary_msg[i:i+8], 2)) for i in range(0, len(binary_msg), 8)])
    
    print("Hidden message found:", message)
    return message

# --- Test it out! ---
# Make sure you have an image named 'Original.png' in the same folder
# Tell Python to look inside the Picture_Encrypt folder for the files
hide_message('Picture_Encrypt/Original.png', 'Hello friend, this is my Cicada test!', 'Picture_Encrypt/encrypted.png')

# Now read it back from the new image
reveal_message('Picture_Encrypt/encrypted.png')