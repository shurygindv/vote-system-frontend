open RsuiteUi;

let callAddingCandidateApi = (name: string, description: string) => {
  Api.addCandidate(~name, ~description);
};

let showSuccesNotification = _ => {
  Notification.success(
    Notification.Props.make(
      ~title=<Text id="Vote.Candidate.Registered" />,
      ~description=<EmptyText />,
      ~placement="bottomStart",
      (),
    ),
  );
};

let showErrorNotification = _ => {
  Notification.error(
    Notification.Props.make(
      ~title=<Text id="Error.Unexpected" />,
      ~description=<Text id="Error.TryLater" size=`sm />,
      ~placement="bottomStart",
      (),
    ),
  );
};

[@react.component]
let make = _ => {
  let (progress, setProgress) = Hooks.useWaitingApi();
  let (formValues, setFormValues) =
    React.useState(_ =>
      {"candidateName": "", "candidateDescription": ""}
    );

  let addCandidate = (candidateName: string, candidateDesc: string) => {
    Js.Promise.(
      callAddingCandidateApi(candidateName, candidateDesc)
      |> then_(_ => {
           setProgress(`resolved);
           showSuccesNotification();
           resolve();
         })
      |> catch(_ => {
           setProgress(`rejected);
           showErrorNotification();
           resolve();
         })
    );
    ();
  };

  let handleSubmit = _ => {
    setProgress(`pending);

    addCandidate(
      formValues##candidateName,
      formValues##candidateDescription,
    );
  };

  <Panel
    header={<Text id="Vote.AddingCandidate" size=`lg bold=true />}>
    <Form
      formValue=formValues
      onSubmit=handleSubmit
      onChange={v => setFormValues(_ => v)}>
      <FormGroup>
        <ControlLabel>
          <Text id="Vote.Candidate.Name" />
        </ControlLabel>
        <FormControl
          _type=`text
          name="candidateName"
          required=true
        />
        <HelpBlock tooltip=true>
          <Text id="Validation.Required" />
        </HelpBlock>
      </FormGroup>
      <FormGroup>
        <ControlLabel>
          <Text id="Vote.Candidate.Goal" />
        </ControlLabel>
        <FormControl
          name="candidateDescription"
          rows=5
          required=true
          componentClass="textarea"
        />
        <HelpBlock tooltip=true>
          <Text id="Validation.Required" />
        </HelpBlock>
      </FormGroup>
      <FormGroup>
        <ButtonToolbar>
          <Button
            loading={progress##isPending}
            appearance=`primary
            _type=`submit>
            <Translator id="Action.Register" />
          </Button>
        </ButtonToolbar>
      </FormGroup>
    </Form>
  </Panel>;
};
