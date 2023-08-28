from docx import Document
import re

def read_word_table(file_path):
    doc = Document(file_path)
    table = doc.tables[0]  # Assuming there is only one table in the document

    time_table_data = []

    for row in table.rows:
        row_data = []
        for col_index, cell in enumerate(row.cells):
            if col_index != 5: 
                row_data.append(cell.text)
        time_table_data.append(row_data)

    return time_table_data

def extract_batch_names(text):
    # Split the cell data on newlines and find batch names in each part
    lines = text.split('\n')
    batch_names = []
    for line in lines:
        matches = re.findall(r'\b(?:BY|B5)\b', line, re.IGNORECASE)
        batch_names.extend(matches)
    return list(set(batch_names))


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
    for data in batchBY:
        print(data)
