import React from 'react'

export default function TodoCard(props) {
    const {children, deleteTodo, index, editTodo} = props
    return (
    <li className='todoItem'>
        {children}
        <div className='actionsContainer'>
            <button onClick={() => {
                editTodo(index)
            }}
            >
                <i className="fa-regular fa-pen-to-square"></i>

            </button>
            <button onClick={()=>{
                deleteTodo(index)
            }}>
                <i className="fa-solid fa-trash"></i>

            </button>

        </div>
    </li>
  )
}
