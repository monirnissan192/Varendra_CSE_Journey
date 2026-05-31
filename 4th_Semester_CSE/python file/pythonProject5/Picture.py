import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import matplotlib.patches as patches

# Load the user's uploaded image
img_path = 'image_bc30fa.png'
img = mpimg.imread(img_path)

# Create a figure and axis
fig, ax = plt.subplots(figsize=(8, 8))
ax.imshow(img)

# Hide axes
ax.axis('off')

# Get image dimensions for scaling relative positions
h, w, _ = img.shape
center_x = w / 2
center_y = h / 2

# 1. Best Sampling Instant (Vertical Center Line)
ax.annotate('Best Sampling Instant', xy=(center_x, h*0.1), xytext=(center_x + w*0.3, h*0.05),
            arrowprops=dict(facecolor='blue', shrink=0.05),
            fontsize=12, fontweight='bold', color='darkblue')

# 2. Decision Threshold (Horizontal Center Line)
ax.annotate('Decision Threshold', xy=(w*0.9, center_y), xytext=(w*0.6, center_y + h*0.35),
            arrowprops=dict(facecolor='blue', shrink=0.05),
            fontsize=12, fontweight='bold', color='darkblue')

# 3. Noise Margin (Vertical Opening)
# Drawing a double-headed arrow for Noise Margin
ax.annotate('', xy=(center_x, h*0.25), xytext=(center_x, h*0.45),
            arrowprops=dict(arrowstyle='<->', color='green', lw=3))
ax.text(center_x + w*0.02, h*0.35, 'Noise Margin\n(Eye Height)', color='green', fontsize=12, fontweight='bold', va='center')

# 4. Timing Margin (Horizontal Opening)
# Drawing a double-headed arrow for Timing Margin
ax.annotate('', xy=(w*0.3, center_y), xytext=(w*0.7, center_y),
            arrowprops=dict(arrowstyle='<->', color='purple', lw=3))
ax.text(center_x, center_y + h*0.08, 'Timing Margin\n(Eye Width)', color='purple', fontsize=12, fontweight='bold', ha='center')

# 5. Jitter / Distortion (Crossing Point)
# Pointing to the left crossing
ax.annotate('Jitter / Distortion\n(Crossing Point)', xy=(0, center_y), xytext=(w*0.1, h*0.85),
            arrowprops=dict(facecolor='red', shrink=0.05),
            fontsize=12, fontweight='bold', color='darkred')

# Show the plot
plt.tight_layout()
plt.show()