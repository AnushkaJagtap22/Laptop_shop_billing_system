from twilio.rest import Client
import os
from dotenv import load_dotenv
import sys

# Load Twilio credentials
load_dotenv()
TWILIO_ACCOUNT_SID = os.getenv('TWILIO_ACCOUNT_SID')
TWILIO_AUTH_TOKEN = os.getenv('TWILIO_AUTH_TOKEN')
TWILIO_WHATSAPP_NUMBER = os.getenv('TWILIO_WHATSAPP_NUMBER')

if not TWILIO_ACCOUNT_SID or not TWILIO_AUTH_TOKEN or not TWILIO_WHATSAPP_NUMBER:
    raise ValueError("Twilio credentials are missing")

client = Client(TWILIO_ACCOUNT_SID, TWILIO_AUTH_TOKEN)

def send_whatsapp(to_number, message_body):
    to_number = f"whatsapp:{to_number}"
    if to_number == TWILIO_WHATSAPP_NUMBER:
        raise ValueError("Recipient number cannot be the same as Twilio number")

    # Restore line breaks
    message_body = message_body.replace('`', '\n')

    message = client.messages.create(
        body=message_body,
        from_=TWILIO_WHATSAPP_NUMBER,
        to=to_number
    )
    print(f"Message sent! SID: {message.sid}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python app.py <to_number> <message>")
        sys.exit(1)

    to_number = sys.argv[1]
    message_body = sys.argv[2]

    send_whatsapp(to_number, message_body)
