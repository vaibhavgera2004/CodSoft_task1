import tkinter as tk
from tkinter import Frame, Label

def respond(event=None):
    user_input = entry.get().strip()
    if user_input == "":
        return

   
    frame_user = Frame(chat_area, bg="#e5ddd5")
    Label(frame_user, text=user_input, bg="#dcf8c6", justify='left', wraplength=300, font=("Arial", 12), padx=5, pady=3).pack(anchor='e', padx=5, pady=2)
    chat_area.window_create(tk.END, window=frame_user)
    chat_area.insert(tk.END, "\n")
    entry.delete(0, tk.END)

    user_input_lower = user_input.lower()
    if "hello" in user_input_lower or "hi" in user_input_lower:
        bot_response = "Hello! How can I assist you regarding the college?\nOptions:\n- courses\n- admissions\n- fees\n- contact information\n- hostel\n- placement\n- events\n- faculty"
    elif "courses" in user_input_lower or "programs" in user_input_lower:
        bot_response = "We offer B.Tech, B.Sc, BCA, MBA, and M.Sc programs."
    elif "admission" in user_input_lower or "apply" in user_input_lower:
        bot_response = "You can apply online on our website or visit the college office with your documents."
    elif "contact" in user_input_lower or "phone" in user_input_lower:
        bot_response = "You can call us at +91-9876543210 or email us at info@college.edu."
    elif "location" in user_input_lower or "address" in user_input_lower:
        bot_response = "We are located at 123 College Road, YourCity, YourState."
    elif "fees" in user_input_lower or "fee structure" in user_input_lower:
        bot_response = "Fee details vary by course. You can check the fee structure on our website under the admissions section."
    elif "scholarship" in user_input_lower:
        bot_response = "Yes, we offer scholarships based on merit and financial need. You can apply during admission."
    elif "hostel" in user_input_lower:
        bot_response = "We provide hostel facilities with clean rooms, Wi-Fi, and mess services for both boys and girls."
    elif "placement" in user_input_lower:
        bot_response = "Our college has a strong placement cell, and top companies visit for campus recruitment with good salary packages."
    elif "events" in user_input_lower:
        bot_response = "We conduct annual cultural fests, tech events, sports meets, and workshops regularly."
    elif "faculty" in user_input_lower:
        bot_response = "Our faculty are well-qualified with years of teaching and industry experience."
    elif "bye" in user_input_lower or "exit" in user_input_lower:
        bot_response = "Goodbye! Feel free to reach out if you need more help."
        add_bot_message(bot_response)
        window.after(1500, window.destroy)
        return
    else:
        bot_response = "Sorry, I didn't understand that. Please ask about courses, admissions, fees, hostel, placements, or contact information."

    add_bot_message(bot_response)

def add_bot_message(message):
    
    frame_bot = Frame(chat_area, bg="#e5ddd5")
    Label(frame_bot, text=message, bg="#f1f0f0", justify='left', wraplength=300, font=("Arial", 12), padx=5, pady=3).pack(anchor='w', padx=5, pady=2)
    chat_area.window_create(tk.END, window=frame_bot)
    chat_area.insert(tk.END, "\n")
    chat_area.see(tk.END)

def clear_placeholder(event):
    if entry.get() == "Type your message here...":
        entry.delete(0, tk.END)
        entry.config(fg="black")

def add_placeholder(event):
    if entry.get() == "":
        entry.insert(0, "Type your message here...")
        entry.config(fg="grey")

window = tk.Tk()
window.title("College Enquiry Chatbot")
window.geometry("500x600")

chat_area = tk.Text(window, wrap=tk.WORD, font=("Arial", 12), bg="#e5ddd5", state=tk.DISABLED)
chat_area.pack(padx=10, pady=10, fill=tk.BOTH, expand=True)
chat_area.config(state=tk.NORMAL)
add_bot_message("Hello! I am CollegeBot. How can I help you today?")

entry = tk.Entry(window, font=("Arial", 14))
entry.bind('<FocusIn>', clear_placeholder)
entry.bind('<FocusOut>', add_placeholder)
entry.bind('<Return>', respond)
entry.pack(padx=10, pady=10, fill=tk.X)

send_button = tk.Button(window, text="Send", font=("Arial", 12), command=respond, bg="#34b7f1", fg="white")
send_button.pack(padx=10, pady=5)

entry.focus()
window.mainloop()