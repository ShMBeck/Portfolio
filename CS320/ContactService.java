import java.util.HashMap;
import java.util.Map;

public class ContactService {
    private Map<String, Contact> contacts = new HashMap<>();

    // Add a contact
    public boolean addContact(Contact contact) {
        if (contacts.containsKey(contact.getContactID())) {
            return false; // Contact with this ID already exists
        }
        contacts.put(contact.getContactID(), contact);
        return true;
    }

    // Delete a contact by ID
    public boolean deleteContact(String contactID) {
        return contacts.remove(contactID) != null;
    }

    // Update a contact's details
    public boolean updateContact(String contactID, String firstName, String lastName, String phone, String address) {
        Contact contact = contacts.get(contactID);
        if (contact == null) {
            return false; // Contact not found
        }
        if (firstName != null) contact.setFirstName(firstName);
        if (lastName != null) contact.setLastName(lastName);
        if (phone != null) contact.setPhone(phone);
        if (address != null) contact.setAddress(address);
        return true;
    }

    // Get a contact by ID
    public Contact getContact(String contactID) {
        return contacts.get(contactID);
    }
}