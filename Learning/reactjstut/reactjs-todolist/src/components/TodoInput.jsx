import React,{useState} from 'react'

export default function TodoInput(props) {

    const {addTodo,todoValue,setTodoValue} = props
    return (
    <header>
        <input placeholder='Enter a task'value={todoValue} onChange={(e)=>{
            setTodoValue(e.target.value)
        }} />
        <button onClick={() =>{
            if(todoValue === '') return alert('Please enter a task')
            addTodo(todoValue)
            setTodoValue('')
        }} > Add</button>
    </header>
  )
}
