def exponential_smoothing(input_value, previous_filtered_value, alpha=0.05):
    filtered_value = (alpha * input_value) + ((1.0 - alpha) * previous_filtered_value)
    return filtered_value

alpha = 0.05  # Smoothing factor (need to edit this factor accordingly)
input = [10, 20, 30, 40, 50, 60, 70] 
filtered_value = 0  # Initial

for value in input:
    filtered_value = exponential_smoothing(value, filtered_value, alpha)
    print(f"Input: {value}, Filtered: {filtered_value}")
