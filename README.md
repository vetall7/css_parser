# CSS Processor

## Introduction

The goal of this project is to create a simple engine for processing CSS. The task involves reading CSS sections interleaved with command sections from standard input. CSS sections should be parsed and placed in appropriate data structures, while command sections should be parsed and executed, with results printed to standard output (marked by ==).

### CSS

Processing starts with reading CSS declarations. CSS is syntactically correct and consists of attribute blocks optionally preceded by selectors. Lack of selectors is legal and indicates attributes applied universally.

- **Selectors:** Separated by commas. Legal CSS selectors are allowed, but it can be assumed they do not contain commas or curly braces.
- **Attribute blocks:** Enclosed in curly braces.
- **Attributes:** Separated by semicolons, composed of a property and a value separated by a colon. A semicolon may or may not follow the last attribute in a block.
- **Attribute Values:** Legal CSS constructions.

### Commands

In the following commands, i and j are positive integers, while n is a legal attribute name.

- **????:** Beginning of command section.
- ******:** Resume CSS reading.
- **?:** Print the number of CSS blocks.
- **i,S,?:** Print the number of selectors for block i (indices starting from 1), skip if the block does not exist.
- **i,A,?:** Print the number of attributes for block i, skip if the block does not exist.
- **i,S,j:** Print the j-th selector for block i (indices starting from 1), skip if the block or selector does not exist.
- **i,A,n:** Print the value of attribute named n for block i, skip if it does not exist.
- **n,A,?:** Print the total count of occurrences of attribute named n across all blocks.
- **z,S,?:** Print the total count of occurrences of selector z across all blocks.
- **z,E,n:** Print the value of attribute named n for selector z, considering the last occurrence. Skip if it does not exist.
- **i,D,*:** Remove entire block i (i.e., selectors + attributes), print "deleted" upon successful deletion.
- **i,D,n:** Remove attribute named n from block i. If the block becomes empty after this operation, remove it along with any selectors. Print "deleted" upon successful deletion.

### Implementation Notes

- Selectors and attributes should be stored as lists.
- CSS blocks should be organized as a doubly linked list.
- When allocating a new node, create an array of T=8 structures to better utilize memory.
- Utilize counters to accelerate operations indexed by cell number.

## Example

#breadcrumb 
{
	width: 80%;
	font-size: 9pt;
}

h1, body {
	min-width: 780px;
	margin: 0;
	padding: 0;
	font-family: "Trebuchet MS", "Lucida Grande", Arial;
	font-size: 85%;
	color: #666666;
}

h1, h2, h3, h4, h5, h6 {color: #0066CB;}
????
?
1,S,?
1,S,1
1,A,?
2,A,font-family
h1,S,?
color,A,?
h1,E,color
1,A,padding
1,D,*
?
2,D,color
?

****
h1, h2, h3, h4, h5, h6 {color: #0066FF;}
????
?
