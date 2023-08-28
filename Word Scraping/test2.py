from docx import Document
import re

def read_word_table(file_path):
    doc = Document(file_path)
    table = doc.tables[0]
    table_data = []
    for row in table.rows:
        row_data = [cell.text for cell in row.cells]
        table_data.append(row_data)
    return table_data

def extract_batch_names(text):
    return re.findall(r'\b(BY|B5)\b', text)

if __name__ == "__main__":
    document_path = "E:\\Download\\BTech5semCSE.docx"
    time_table_data = read_word_table(document_path)

    print(":: Time Table ::")
    print('\nInput data :')
    for data in time_table_data:
        print(data)

    batchBY = []

    print('\nTime Schedule : \n')

    for row_data in time_table_data:
        batchBYrow = []
        for cell_data in row_data:
            cell_data = cell_data.replace('\n', ' ')  # Remove the newline characters from the cell data
            batches = extract_batch_names(cell_data)
            if batches:
                batchBYrow.extend(batches)
        batchBY.append(batchBYrow)

    # Printing Time Table like a Time Table
    print('Output table after processing :')

    # Get the maximum number of columns in the time table
    max_cols = max(len(row) for row in time_table_data)

    # Print the time slots row
    print(''.ljust(25), end='')
    for slot in time_table_data[0][1:]:
        print(slot.ljust(20), end='')
    print()

    # Loop through each day and its corresponding time slots
    for day, *slots in zip(*time_table_data):
        print(day.ljust(25), end='')
        for slot in slots[1:]:  # Skip the first element (day) in each row
            print(slot.ljust(20), end='')
        print()
