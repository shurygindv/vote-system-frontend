open RsuiteUi;

let items = [{
    "candidateName": "Ivanov",
    "rate": 5,
    "candidateDescription": "dsds",
  }, {
    "candidateName": "Ivanov",
    "rate": 10,
    "candidateDescription": "dsds",
  }, {
    "candidateName": "Ivanov",
    "rate": 12,
    "candidateDescription": "dsds",
 }];

[@react.component]
let make = _ => {
  
 <Panel
    header={<Text id="Vote.Rating" size=`lg bold=true />}>
     <Table
          height={420}
          data={items}
          onSortColumn={(sortColumn, _sortType) => {
            Js.log(sortColumn);
          }}
        >
          <Table.Column width={50} align=`center flexGrow={1}>
            <Table.HeaderCell>
              <Text id="Vote.Candidate.Name" />
            </Table.HeaderCell>
            <Table.Cell dataKey="candidateName" />
          </Table.Column>

          <Table.Column width={100} align=`center flexGrow={2}>
            <Table.HeaderCell>
                <Text id="Vote.Candidate.Description" />
            </Table.HeaderCell>
            <Table.Cell dataKey="candidateDescription" />
          </Table.Column>

          <Table.Column flexGrow={1}  >
            <Table.HeaderCell>
              <Text id="Vote.Rating" bold={true} />
            </Table.HeaderCell>
            <Table.Cell dataKey="rate" />
          </Table.Column>
        </Table>
  </Panel>
};
